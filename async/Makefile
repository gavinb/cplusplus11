
CXXFLAGS=--std=c++11 -Wall -Wno-format

ANALYZE=c++ --analyze $(CXXFLAGS)

SOURCES=async_ex0.cpp		\
	async_ex1.cpp		\
	async_ex2.cpp

TARGETS=$(SOURCES:%.cpp=%)

OBJS=$(SOURCES:%.cpp=%.o)

DIAGS=$(SOURCES:%.cpp=%.plist)

all:	$(TARGETS)

lint:	#
		$(ANALYZE) $(SOURCES)

clean:	#
		-rm -f $(TARGETS) $(OBJS) $(DIAGS)
