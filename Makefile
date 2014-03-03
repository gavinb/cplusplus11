
SUBDIRS=async				\
		chrono				\
		regex				\
		smart_pointers		\
		string				\
		threads

all:	#
		for d in $(SUBDIRS); do make -C $$d ; done

clean:	#
		for d in $(SUBDIRS); do make -C $$d clean ; done
