#include <iostream>
#include <cstdio>
#include <cassert>

#include "hyperleveldb/db.h"
#include "hyperleveldb/filter_policy.h"
#include "db/db_impl.h"
#include "db/filename.h"
#include "db/version_set.h"
#include "db/write_batch_internal.h"
#include "hyperleveldb/cache.h"
#include "hyperleveldb/env.h"
#include "hyperleveldb/table.h"
#include "util/hash.h"
#include "util/logging.h"
#include "util/mutexlock.h"
#include "util/testharness.h"
#include "util/testutil.h"

int main(int argc, char** argv) {
  printf("hello\n");

  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
  assert(status.ok());
  db->Put(leveldb::WriteOptions(), "a", "b");
}