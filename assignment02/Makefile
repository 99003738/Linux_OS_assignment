
PROJECT_NAME = assignment_02

SRC = 



all : 
	make chat
	make circular_buffer
	make chat_app
	make consumer_prob
	make msg_received
	make msg_send
	make Mutex
	make producer_shared
	make semaphore01
	make server_06
	make stack_semaphore
	make test





chat: chat_02.c common.h
	gcc chat_02.c -o chat_02.out

circular_buffer: circular_buffer.c common.h
	gcc circular_buffer.c -o circular.out
chat_app: chat_application.c common.h
	gcc chat_application.c -o chat_app.out
consumer_prob: consumer_prblm.c common.h
	gcc consumer_prblm.c -o consumer.out
msg_received : Msg_received.c common.h
	gcc Msg_received.c -o msgreceived.out
msg_send : Msg_send.c common.h
	gcc Msg_send.c -o msgsend.out
Mutex : Mutex.c common.h
	gcc Mutex.c -o common.h
producer_shared: producer_shared.c common.h
	gcc producer_shared.c -o producer.out
semaphore01: semaphore01.c common.h
	gcc semaphore01.c -o semaphore.out
server_06: server_06.c common.h
	gcc server_06.c -o server_06.out
stack_semaphore: stack_semaphore.c common.h
	gcc stack_semaphore.c -o stack_sema.out
test : test.c common.h
	gcc test.c -o test.out





analysis:
	cppcheck $(SRC)

memcheck: $(PROJECT_NAME).out
	valgrind ./$(PROJECT_NAME).out

coverage:${PROJECT_NAME}.out
	gcc -fprofile-arcs -ftest-coverage $(SRC) -I $(INC) -o $(PROJECT_NAME).out
	./${PROJECT_NAME}.out
	gcov -a $(SRC)

codesize:${PROJECT_NAME}.out
	size ./${PROJECT_NAME}.out



