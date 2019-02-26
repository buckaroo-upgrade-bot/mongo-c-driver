load('//:subdir_glob.bzl', 'subdir_glob')
load('//:buckaroo_macros.bzl', 'buckaroo_deps')

genrule(
  name = 'bson-version',
  out = 'bson-version.h',
  srcs = [
    'src/libbson/src/bson/bson-version.h.in',
  ],
  cmd = ' && '.join([
    'cp $SRCS $OUT',
    'sed -i "s/@BSON_MAJOR_VERSION@/0/g" $OUT',
    'sed -i "s/@BSON_MINOR_VERSION@/0/g" $OUT',
    'sed -i "s/@BSON_MICRO_VERSION@/0/g" $OUT',
    'sed -i "s/@BSON_VERSION@/0.0.0/g" $OUT',
    'sed -i "s/@BSON_PRERELEASE_VERSION@//g" $OUT',
  ]),
)

genrule(
  name = 'bson-config',
  out = 'bson-config.h',
  srcs = [
    'src/libbson/src/bson/bson-config.h.in',
  ],
  cmd = ' && '.join([
    'cp $SRCS $OUT',
    'sed -i "s/@BSON_OS@/1/g" $OUT',
    'sed -i "s/@BSON_BYTE_ORDER@/1234/g" $OUT',
    'sed -i "s/@BSON_HAVE_ATOMIC_32_ADD_AND_FETCH@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_ATOMIC_64_ADD_AND_FETCH@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_CLOCK_GETTIME@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_STRINGS_H@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_STRNLEN@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_SNPRINTF@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_GMTIME_R@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_REALLOCF@/0/g" $OUT',
    'sed -i "s/@BSON_HAVE_TIMESPEC@/1/g" $OUT',
    'sed -i "s/@BSON_EXTRA_ALIGN@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_SYSCALL_TID@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_RAND_R@/1/g" $OUT',
    'sed -i "s/@BSON_HAVE_STDBOOL_H@/1/g" $OUT',
  ]),
)

gcc_pp_flags = [
  '-DBSON_COMPILATION=1',
  '-DMONGOC_COMPILATION=1',
]

cxx_library(
  name = 'bson',
  header_namespace = '',
  exported_headers = dict(
    subdir_glob([
      ('src/common', '**/*.h'),
      ('src/libbson/src', '**/*.h'),
    ]).items() + [
      ('bson/bson-version.h', ':bson-version'),
      ('bson/bson-config.h', ':bson-config'),
      ('bson.h', 'src/libbson/src/bson/bson.h'),
    ]
  ),
  srcs = glob([
    'src/common/**/*.c',
    'src/libbson/src/**/*.c',
  ]),
  platform_preprocessor_flags = [
    ('^macos.*', gcc_pp_flags),
    ('^linux.*', gcc_pp_flags),
  ],
  exported_post_platform_linker_flags = [
    ('linux.*', [ '-lpthread' ]),
  ],
  visibility = [
    'PUBLIC',
  ],
)

genrule(
  name = 'mongoc-version',
  out = 'mongoc-version.h',
  srcs = [
    'src/libmongoc/src/mongoc/mongoc-version.h.in',
  ],
  cmd = ' && '.join([
    'cp $SRCS $OUT',
    'sed -i "s/@MONGOC_MAJOR_VERSION@/0/g" $OUT',
    'sed -i "s/@MONGOC_MINOR_VERSION@/0/g" $OUT',
    'sed -i "s/@MONGOC_MICRO_VERSION@/0/g" $OUT',
  ]),
)

genrule(
  name = 'mongoc-config',
  out = 'mongoc-config.h',
  srcs = [
    'src/libmongoc/src/mongoc/mongoc-config.h.in',
  ],
  cmd = ' && '.join([
    'cp $SRCS $OUT',
    'sed -i "s/@MONGOC_USER_SET_CFLAGS@//g" $OUT',
    'sed -i "s/@MONGOC_USER_SET_LDFLAGS@//g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_CRYPTO_CNG@/0/g" $OUT',
    'sed -i "s/@MONGOC_SOCKET_ARG2@/struct sockaddr/g" $OUT',
    'sed -i "s/@MONGOC_SOCKET_ARG3@/socklen_t/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_ICU@/0/g" $OUT',
    'sed -i "s/@MONGOC_TRACE@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SHM_COUNTERS@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_COMPRESSION@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_COMPRESSION_ZLIB@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_COMPRESSION_SNAPPY@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_RDTSCP@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_SCHED_GETCPU@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SSL_SECURE_CHANNEL@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_RES_NSEARCH@/1/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_RES_NDESTROY@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_RES_NCLOSE@/1/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_DNSAPI@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SSL_LIBRESSL@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_RES_SEARCH@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_CRYPTO_LIBCRYPTO@/1/g" $OUT',
    'sed -i "s/@MONGOC_NO_AUTOMATIC_GLOBALS@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_SOCKLEN@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SASL_SSPI@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_ASN1_STRING_GET0_DATA@/0/g" $OUT',
    'sed -i "s/@MONGOC_HAVE_SASL_CLIENT_DONE@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SASL@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SASL_CYRUS@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SSL_OPENSSL@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_CRYPTO@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SSL@/1/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_CRYPTO_SYSTEM_PROFILE@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_CRYPTO_COMMON_CRYPTO@/0/g" $OUT',
    'sed -i "s/@MONGOC_ENABLE_SSL_SECURE_TRANSPORT@/0/g" $OUT',
  ]),
)

macos_srcs = glob([
  'src/libmongoc/src/mongoc/mongoc-rand-common-crypto.c',
])

windows_srcs = glob([
  'src/libmongoc/src/mongoc/mongoc-rand-cng.c',
])

platform_srcs = macos_srcs + windows_srcs

cxx_library(
  name = 'mongoc',
  header_namespace = '',
  exported_headers = dict(
    subdir_glob([
      ('src/common', '**/*.h'),
      ('src/libmongoc/src', '**/*.h'),
    ]).items() + [
      ('mongoc.h', 'src/libmongoc/src/mongoc/mongoc.h'),
      ('mongoc/mongoc-config.h', ':mongoc-config'),
      ('mongoc/mongoc-version.h', ':mongoc-version'),
    ]
  ),
  headers = subdir_glob([
    ('src/libmongoc/src/mongoc', '**/*.defs'),
    ('src/libmongoc/src/mongoc', '**/*.def'),
    ('src/libmongoc/src', '**/*.def'),
  ]),
  srcs = glob([
    'src/libmongoc/src/**/*.c',
  ]),
  platform_preprocessor_flags = [
    ('^macos.*', gcc_pp_flags),
    ('^linux.*', gcc_pp_flags),
  ],
  platform_srcs = [
    ('macos.*', macos_srcs),
    ('windows.*', windows_srcs),
  ],
  deps = buckaroo_deps() + [
    ':bson',
  ],
  exported_post_platform_linker_flags = [
    ('linux.*', [ '-lrt', '-lresolv' ]),
  ],
  visibility = [
    'PUBLIC',
  ],
)
