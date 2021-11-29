.PHONY : all

all : ring dist_reduction_sum dist_reduction_product_bcast main

ring : ring.c
	mpicc -o ring.out ring.c

dist_reduction_sum : dist_reduction_sum.c
	mpicc -o dist_reduction_sum.out dist_reduction_sum.c

dist_reduction_product_bcast : dist_reduction_product_bcast.c
	mpicc -o dist_reduction_product_bcast.out dist_reduction_product_bcast.c

main : main.c
	gcc -o main.out main.c

test : test.c
	gcc -o test.out test.c

.PHONY : clean

clean :
	rm *.out