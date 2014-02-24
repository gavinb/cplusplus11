
CXXFLAGS=--std=c++11 -Wall -Wno-format

ANALYZE=c++ --analyze $(CXXFLAGS)

SOURCES=cpp11_shared_ptr_ex1.cpp	\
		cpp11_unique_ptr_ex1.cpp	\
		cpp11_unique_ptr_ex2.cpp	\
		cpp11_unique_ptr_ex3.cpp	\
		cpp11_unique_ptr_ex4.cpp	\
		cpp11_unique_ptr_ex5.cpp	\
#		cpp11_weak_ptr_ex1.cpp		\
#		cpp11_weak_ptr_ex2.cpp

TARGETS=$(SOURCES:%.cpp=%)

OBJS=$(SOURCES:%.cpp=%.o)

DIAGS=$(SOURCES:%.cpp=%.plist)

all: $(TARGETS)

lint:	#
		$(ANALYZE) $(SOURCES)

clean:	#
		-rm -f $(TARGETS) $(OBJS) $(DIAGS)
