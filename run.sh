/usr/bin/g++ -c -g -Wall -m64 -std=c++14 -pthread -fPIC -O3 -Iinclude -I/usr/include/python3.5m -I/usr/include/x86_64-linux-gnu/python3.5m -o utils.o utils.cpp
/usr/bin/g++ -c -g -Wall -m64 -std=c++14 -pthread -fPIC -O3 -Iinclude -I/usr/include/python3.5m -I/usr/include/x86_64-linux-gnu/python3.5m -o convexhull.o convexhull.cpp
/usr/bin/g++ -c -g -Wall -m64 -std=c++14 -pthread -fPIC -O3 -Iinclude -I/usr/include/python3.5m -I/usr/include/x86_64-linux-gnu/python3.5m -o exposed.o exposed.cpp

/usr/bin/g++ utils.o convexhull.o exposed.o -g -Wall -m64 -std=c++14 -shared -lboost_python-py35 -lpython3.5m -o libcavehull.so