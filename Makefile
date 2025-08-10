objects = main.o modules/auw.o modules/ciw.o modules/cw.o modules/obw.o modules/toc.o

.PHONY: all boost wt build run clean distclean sysrep

all: boost wt build run

boost_1_88_0.tar.gz:
	@if [ ! -d local/boost ]; then \
		wget https://archives.boost.io/release/1.88.0/source/boost_1_88_0.tar.gz; \
	fi

boost_1_88_0: boost_1_88_0.tar.gz
	@if [ ! -d local/boost ]; then \
		tar -xf boost_1_88_0.tar.gz; \
		rm -r boost_1_88_0.tar.gz; \
	fi

local/boost: boost_1_88_0
	@if [ ! -d local/boost ]; then \
		cd boost_1_88_0; \
		./bootstrap.sh; \
	fi

local/boost/.done: local/boost
	@if [ ! -f local/boost/.done ]; then \
		cd boost_1_88_0; \
		./b2 --prefix=$(PWD)/local/boost install; \
		cd ../ && touch $@; \
		rm -r $(PWD)/boost_1_88_0; \
	fi

boost: local/boost/.done

4.12.0.tar.gz: boost
	@if [ ! -d local/wt ]; then \
		wget https://github.com/emweb/wt/archive/refs/tags/4.12.0.tar.gz; \
	fi

wt-4.12.0: 4.12.0.tar.gz
	@if [ ! -d local/wt ]; then \
		tar -xf 4.12.0.tar.gz; \
		rm -r 4.12.0.tar.gz; \
	fi

wt-4.12.0/build: wt-4.12.0
	@if [ ! -d local/wt ]; then \
		cd wt-4.12.0; \
		mkdir build; \
		cd build; \
		cmake ../ -DBOOST_ROOT=$(PWD)/local/boost -DBoost_LIBRARY_DIRS=$(PWD)/local/boost/lib -DCMAKE_INSTALL_PREFIX=$(PWD)/local/wt; \
	fi

local/wt/.done: wt-4.12.0/build
	@if [ ! -f local/wt/.done ]; then \
		cd wt-4.12.0/build; \
		make; \
		make install; \
		cd ../../ && touch $@; \
		rm -r wt-4.12.0; \
	fi

wt: local/wt/.done boost

modules/auw.o: modules/auw.cpp wt
	g++ -I$(PWD)/local/wt/include -c -o modules/auw.o modules/auw.cpp

modules/ciw.o: modules/ciw.cpp wt
	g++ -I$(PWD)/local/wt/include -c -o modules/ciw.o modules/ciw.cpp

modules/cw.o: modules/cw.cpp wt
	g++ -I$(PWD)/local/wt/include -c -o modules/cw.o modules/cw.cpp

modules/obw.o: modules/obw.cpp wt
	g++ -I$(PWD)/local/wt/include -c -o modules/obw.o modules/obw.cpp

modules/toc.o: modules/toc.cpp wt
	g++ -I$(PWD)/local/wt/include -c -o modules/toc.o modules/toc.cpp

main.o: main.cpp wt
	g++ -I$(PWD)/local/wt/include -c -o main.o main.cpp

build: $(objects) wt
	g++ -o main $(objects) $(PWD)/local/wt/lib/libwt.so $(PWD)/local/wt/lib/libwthttp.so -L$(PWD)/local/boost/lib -lboost_program_options -lboost_filesystem -lboost_system -lboost_thread -pthread

run: build
	sed -i 's|<debug-level>.*</debug-level>|<debug-level>all</debug-level>|' $(PWD)/local/wt/etc/wt/wt_config.xml
	LD_LIBRARY_PATH=$(PWD)/local/boost/lib:$(PWD)/local/wt/lib:$$LD_LIBRARY_PATH ./main --debug-level all --docroot . --resources $(PWD)/local/wt/share/Wt/resources --http-address 0.0.0.0 --http-port 8080

clean:
	rm -f build *.o modules/*.o main

distclean: clean
	rm -r local

sysrep:
	sudo apt install -y g++ git make cmake
