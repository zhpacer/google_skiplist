// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"
#include "AnalysisInfo.h"
#include <map>
#include <set>

using namespace std;
using namespace leveldb;


namespace leveldb {

typedef uint64_t Key;

struct Comparator {
  int operator()(const Key& a, const Key& b) const {
    if (a < b) {
      return -1;
    } else if (a > b) {
      return +1;
    } else {
      return 0;
    }
  }
};

}  // namespace leveldb


#define TEST_NUM 100000
int main(int argc, char** argv) {

  leveldb::Arena arena;
  leveldb::Comparator cmp;
	AnalysisInfo ana;
  leveldb::SkipList<leveldb::Key,leveldb::Comparator> sList(cmp,&arena);
  map<leveldb::Key,leveldb::Key> tMap,uniMap;

  leveldb::Key *data = new leveldb::Key[TEST_NUM];
  for(int i=0;i<TEST_NUM;) {
    data[i] = rand();
    if(!uniMap.count(data[i])) {
      uniMap[data[i]] = 1;
      ++i;
    }
    
  }

  fprintf(stderr,"skiplist test!\n");
  fprintf(stderr,"Test insert\n");
  ana.TimeStart();
  for(int i=0;i<TEST_NUM;++i) {
    sList.Insert(Key(data[i]));
  }
  ana.TimeEnd();
  fprintf(stderr, "skiplist uses %fms for insert %d items\n",ana.TimeEval(),TEST_NUM );

  ana.TimeStart();
  for(int i=0;i<TEST_NUM;++i) {
    tMap.insert(pair<leveldb::Key,leveldb::Key>(data[i],data[i]));
  }
  ana.TimeEnd();
  fprintf(stderr, "map uses %fms for insert %d items\n",ana.TimeEval(),TEST_NUM );

  fprintf(stderr,"Test find\n");
  ana.TimeStart();
  for(int i=0;i<TEST_NUM;++i) {
    sList.Contains((data[i]));
  }
  ana.TimeEnd();
  fprintf(stderr, "skiplist uses %fms for find %d items\n",ana.TimeEval(),TEST_NUM );

  ana.TimeStart();
  for(int i=0;i<TEST_NUM;++i) {
    tMap.find(data[i]);
  }
  ana.TimeEnd();
  fprintf(stderr, "map uses %fms for find %d items\n",ana.TimeEval(),TEST_NUM );


}
