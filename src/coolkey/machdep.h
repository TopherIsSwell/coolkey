/* ***** BEGIN COPYRIGHT BLOCK *****
 * Copyright (C) 2005 Red Hat, Inc.
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation version
 * 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * ***** END COPYRIGHT BLOCK *****/

#ifndef COOLKEY_MACHDEP_H
#define COOLKEY_MACHDEP_H
/*
 * abstract away os dependencies in shared memory system
 */

struct SHMemData;

class SHMem {
private:
    SHMemData *shmemData;
    SHMem();
public:
    ~SHMem();
    char *getSHMemAddr();
    int getSHMemSize();
    static SHMem  *initSegment(const char *name, int size, bool &init);
};

struct OSLockData;
class OSLock {
private:
   OSLockData *lockData;
   static bool needThread;
public:
   OSLock(bool exceptionAllowed = true);
   ~OSLock();
   bool isValid();
   void getLock();
   void releaseLock();
   static void setThreadSafe(bool thread) { needThread = thread; }
};

typedef unsigned long OSTime;
OSTime OSTimeNow(void);

void OSSleep(int time);

#define USE_SHMEM
#endif
