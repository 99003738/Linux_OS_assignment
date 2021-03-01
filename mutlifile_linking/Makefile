


all :
	make OS_child
	make child
	make main
	make welcome_child



child: linux_child.c common.h
	gcc linux_child.c -o child.out

main : main.c common.h
	gcc main.c -o main.out
OS_child: OS_child.c common.h
	gcc OS_child.c -o OS_child.out
welcome_child: welcome_child.c common.h
	gcc welcome_child.c -o welcome.out