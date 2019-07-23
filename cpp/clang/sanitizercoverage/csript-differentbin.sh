# -fsanitize-blacklist=blacklist
if [ -z "$1" ]
then
	filename="trace-pc-guard"
else
     filename=$1
fi
/usr/bin/clang++ -g  -fsanitize-coverage=trace-pc-guard $filename-example.cc -c
/usr/bin/clang++ $filename-cb.cc $filename-example.o -fsanitize=address -fsanitize-blacklist=blacklist
ASAN_OPTIONS=strip_path_prefix=`pwd`/ ./a.out $2 $3
