output_dir=out
staticBinFile=out/bin/client
sharedBinFile=out/bin/sharedclient
cpp_src=$(wildcard *.cpp)
includes=$(wildcard *.h)

obj=${cpp_src:.cpp=.o}

static: ${obj}
		ar rcs out/static/libmynet.a out/static/*.o

shared: ${obj}
		g++ -shared run/main.cpp out/shared/*.o -o out/shared/libmynet.so

run_static:	static
		g++ run/main.cpp -Lout/static -lmynet -o ${staticBinFile}
		./${staticBinFile}

run_shared: shared
		g++ main.cpp -Lout/shared -lmynet -o ${sharedBinFile}
		LD_LIBRARY_PATH=$(pwd)/out/shared ./${sharedBinFile}


%.o : %.cpp ${includes}
		g++ -c $< -o out/static/$@
		g++ -fPIC -c $< -o out/shared/$@

clean:
	rm *.o out/shared/*.o out/static/*.o
