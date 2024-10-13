
CPPFLAGS="-std=c++17 -g"

###

cd source
g++ ${CPPFLAGS} -I../include -c $1.cpp -o $1.opp

