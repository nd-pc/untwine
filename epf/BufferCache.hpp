/*****************************************************************************
 *   Copyright (c) 2020, Hobu, Inc. (info@hobu.co)                           *
 *                                                                           *
 *   All rights reserved.                                                    *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 3 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 ****************************************************************************/


#pragma once

#include <deque>
#include <mutex>
#include <condition_variable>

#include "EpfTypes.hpp"

namespace ept2
{
namespace epf
{

// This is simply a cache of data buffers to avoid continuous allocation and deallocation.
class BufferCache
{
public:
    BufferCache() : m_count(0)
    {}

    DataVecPtr fetch();
    void replace(DataVecPtr&& buf);

private:
    std::deque<DataVecPtr> m_buffers;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    int m_count;
};

} // namespace epf
} // namespace ept2
