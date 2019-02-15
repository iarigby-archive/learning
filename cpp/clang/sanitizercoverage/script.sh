clang++ -g  -fsanitize-coverage=bb,no-prune,trace-pc-guard $1-example.cc -c
clang++ $1-cb.cc $1-example.o -fsanitize=address
ASAN_OPTIONS=strip_path_prefix=`pwd`/ ./a.out $2 $3