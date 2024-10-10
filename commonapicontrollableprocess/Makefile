CXX = g++
CXXFLAGS = -Wall -Wextra -pthread -O2 -fPIC -std=c++17

PREFIX ?= /usr/local
LIBDIR = $(PREFIX)/lib64/comapi
INCLUDEDIR = $(PREFIX)/include/comapi

LIBNAME = libcommonapicontrollableprocess
INCLUDES = -I/usr/local/include/comapi -Iinclude

SRCS = src/controllableProcess.cpp

OBJS = $(SRCS:.cpp=.o)

SHARED_LIB = $(LIBNAME).so

all: $(SHARED_LIB)

$(SHARED_LIB): $(OBJS)
	@echo "Creating shared library $@"
	$(CXX) -shared -o $@ $(OBJS)

src/%.o: src/%.cpp
	@echo "Compiling $< into $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@


install: all
	mkdir -p $(LIBDIR) $(INCLUDEDIR)
	install -m 0755 $(SHARED_LIB) $(LIBDIR)
	@echo "Installing header files to $(INCLUDEDIR)"
	cp -r ./include/comapi/* $(INCLUDEDIR)

uninstall:
	rm -f $(LIBDIR)/$(SHARED_LIB)
	rm -rf $(INCLUDEDIR)/controllableProcess

clean:
	@echo "Cleaning up"
	rm -f $(OBJS) $(SHARED_LIB)

.PHONY: all clean
