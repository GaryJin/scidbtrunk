/*
**
* BEGIN_COPYRIGHT
*
* Copyright (C) 2008-2015 SciDB, Inc.
* All Rights Reserved.
*
* SciDB is free software: you can redistribute it and/or modify
* it under the terms of the AFFERO GNU General Public License as published by
* the Free Software Foundation.
*
* SciDB is distributed "AS-IS" AND WITHOUT ANY WARRANTY OF ANY KIND,
* INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY,
* NON-INFRINGEMENT, OR FITNESS FOR A PARTICULAR PURPOSE. See
* the AFFERO GNU General Public License for the complete license terms.
*
* You should have received a copy of the AFFERO GNU General Public License
* along with SciDB.  If not, see <http://www.gnu.org/licenses/agpl-3.0.html>
*
* END_COPYRIGHT
*/

/**
 * @file CircularArray.h
 *
 * @brief The implementation of the array iterator for the circular_window operator
 *
 * @author Jin Shi <qq362257632@hotmail.com>
 *
 */

#ifndef CIRCULAR_ARRAY_H_
#define CIRCULAR_ARRAY_H_

#include <string>
#include <vector>

#include <array/DelegateArray.h>
#include <array/Metadata.h>
#include <query/FunctionDescription.h>
#include <query/Expression.h>
#include <query/Aggregate.h>
#include <array/MemArray.h>
#include <query/ops/aggregates/WindowArray.h>

namespace scidb
{
    class WindowCircularArray;
    class WindowCircularArrayIterator;
    class MaterializedCWindowChunkIterator;

/**
 *   Used to process data in an input Chunk consumed/processed by window(...)
 *
 *   This structure is used within the window(...) operator to represent the
 *  state of each input data chunk as it is being processed. Access to the
 *  WindowChunk's state is through the WindowChunkIterator classes. Within
 *  the WindowChunk we process cells from the InputChunk, and for each
 *  "window" of cells in the InputChunk (where the size and shape of the
 *  window is taken from the operator's argument list).
 *
 */
    class WindowCircularChunk : public ConstChunk
    {
        friend class MaterializedCWindowChunkIterator;

    public:
        WindowCircularChunk(WindowCircularArray const& array, AttributeID attrID);

        virtual const ArrayDesc& getArrayDesc() const;
        virtual const AttributeDesc& getAttributeDesc() const;
        virtual Coordinates const& getFirstPosition(bool withOverlap) const;
        virtual Coordinates const& getLastPosition(bool withOverlap) const;
        virtual std::shared_ptr<ConstChunkIterator> getConstIterator(int iterationMode) const;
        virtual int getCompressionMethod() const;
        virtual Array const& getArray() const;

        /**
         *  When using the materialize algorithm, calculate by how much to step the iterator when it leaves the window(...)
         */
        inline uint64_t getStep() const;

        /**
         *   Set position within chunk referred to by the Iterator.
         */
        void setPosition(WindowCircularArrayIterator const* iterator, Coordinates const& pos);

    private:
        void materialize();
        void pos2coord(uint64_t pos, Coordinates& coord) const;
        uint64_t coord2pos(const Coordinates& coord) const;
        inline bool valueIsNeededForAggregate (const Value & val, const ConstChunk & inputChunk) const;

        WindowCircularArray const& _array;
        WindowCircularArrayIterator const* _arrayIterator;
        size_t _nDims;
        Coordinates _arrSize;
        Coordinates _firstPos;
        Coordinates _lastPos;
        AttributeID _attrID;
        AggregatePtr _aggregate;

        //
        //  The existing implementation computes two maps when it decides to
        // materialize a chunk. One of all of the cells in the input chunk that
        // are not missing (_inputMap), and the second of all the cells in the
        // input chunk that are not in the overlapping region (_stateMap).
        std::map<uint64_t, bool> _stateMap;
        std::map<uint64_t, Value> _inputMap;

        //  TODO: We can eliminate one of these two trees, saving space and time.
        //        The idea is to store a single physical tree with elements of
        //        the tree containing enough information to distinguish when
        //        an attribute's contains a missing code (and can therefore
        //        be ignored for the purposes of computing the aggregate, but
        //        must be used as the "center" of an output window computation)
        //        or not.
        bool _materialized;
        std::shared_ptr<CoordinatesMapper> _mapper;

        /**
         *   Returns true if the chunk's processing algorithm materializes input chunk.
         */
        inline bool isMaterialized() const { return _materialized; };

        Value _nextValue;
    };


    class MaterializedCWindowChunkIterator : public ConstChunkIterator
    {
    public:
        MaterializedCWindowChunkIterator(WindowCircularArrayIterator const& arrayIterator, WindowCircularChunk const& aChunk, int mode);

        virtual int getMode() const;
        virtual bool isEmpty() const;
        virtual Value const& getItem();
        virtual void operator ++();
        virtual bool end();
        virtual Coordinates const& getPosition();
        virtual bool setPosition(Coordinates const& pos);
        virtual void reset();
        ConstChunk const& getChunk();

    private:
        void calculateNextValue();
        void stepToNextValidValue();

        WindowCircularArray const& _array;
        WindowCircularChunk const& _chunk;
        AggregatePtr _aggregate;
        Value _defaultValue;
        int _iterationMode;
        Value _nextValue;

        std::map<uint64_t, bool>const& _stateMap;
        std::map<uint64_t, Value>const& _inputMap;
        std::map<uint64_t, bool>::const_iterator _iter;

        inline bool posIsWithinOverlap ( Coordinates const& pos ) const;
        inline bool posIsWithinOverlap ( uint64_t const& pos ) const;

        Coordinate _currPos;
        Coordinate _numToCalculate;

        size_t _nDims;
        Coordinates _coords;

    };

    class WindowCircualrArrayIterator : public ConstArrayIterator
    {
        friend class WindowCircularChunk;
        friend class MaterializedCWindowChunkIterator;
    public:
        virtual ConstChunk const& getChunk();
        virtual bool end();
        virtual void operator ++();
        virtual Coordinates const& getPosition();
        virtual bool setPosition(Coordinates const& pos);
        virtual void reset();

        /**
         * Return the algorithm named in the AFL window(...) expression.
         *
         * @return string containing name of algorithm being used
         */
        std::string const& getMethod() const { return _method; };

        WindowCircularArrayIterator(WindowCircularArray const& array, AttributeID id, AttributeID input, std::string const& method);

    private:
        WindowCircularArray const& array;
        std::shared_ptr<ConstArrayIterator> iterator;
        Coordinates currPos;
        bool hasCurrent;
        WindowCircularChunk chunk;
        bool chunkInitialized;
        std::string _method;

    };

    class WindowCircularArray : public Array
    {
        friend class WindowCircularArrayIterator;
        friend class MaterializedCWindowChunkIterator;
        friend class WindowCircularChunk;

    public:
        virtual ArrayDesc const& getArrayDesc() const;
        virtual std::shared_ptr<ConstArrayIterator> getConstIterator(AttributeID attr) const;

        WindowCircularArray(ArrayDesc const& desc,
                    std::shared_ptr<Array> const& inputArray,
                    std::vector<AttributeID> const& inputAttrIDs,
                    std::vector <AggregatePtr> const& aggregates,
                    std::string const& method);

        static const std::string PROBE;
        static const std::string MATERIALIZE;

    private:
        ArrayDesc _desc;
        ArrayDesc _inputDesc;
        Dimensions _dimensions;
        std::shared_ptr<Array> _inputArray;
        std::vector<AttributeID> _inputAttrIDs;
        std::vector <AggregatePtr> _aggregates;
        std::string _method;

    };

}

#endif  //CIRCULAR_ARRAY_H_
