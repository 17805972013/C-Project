define run-cc
	cc -o m4 m1.o
endef
#subsystem:
#	cd ../day21&& $(MAKE)
object=m1.c m2.c m3.c
object1=$(object:.c=.o)
m4:$(object1)
	$(run-cc)
m1.o:m1.c m2.c m3.c
	cc -c m1.c
m2.o:m2.c
	cc -c m2.c
m3.o:m3.c
	cc -c m3.c
clean:
	rm -f m4 *.o
all:
	@echo $(object1);
