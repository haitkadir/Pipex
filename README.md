# Pipex
### information gathering :)
- fork
  - `fork()` Function creates child process from main process
    ```c
        printf("hello world\n");
        /*
        Output:

            hello world

        */
    ```
  - Using fork
    ```c
        fork();
        printf("hello world\n");
        /*
        Output:

            hello world
            hello world
        
        */
    ```

- wait
  - `wait()` Function stops a process until the other processes finished
    ```c
        int id = fork();
        printf("%s %d\n", "Hello world 1:", id);
        printf("%s %d\n", "Hello world 2:", id);
        /*
        Output:

            Hello world 1: 29462
            Hello world 2: 29462
            Hello world 1: 0
            Hello world 2: 0

        */
    ```
  - Using fork
    ```c
    int id = fork();
        if (id != 0)
            wait(NULL);
        printf("%s %d\n", "Hello world 1:", id);
        printf("%s %d\n", "Hello world 2:", id);
        /*
        Output:

            Hello world 1: 0
            Hello world 2: 0
            Hello world 1: 29462
            Hello world 2: 29462
        
        */
    ```
- getpid, getppid
  - `getpid()` Function gets the pid of the current process
  - `getppid()` Function gets the pid of parent of the current process
    ```c
        printf("%s %d\n", "pid of current process:", getpid());
		printf("%s %d\n", "pid of parent of current process:", getppid());
        /*
        Output:

            pid of current process: 7186
			pid of parent of current process: 4822

        */
    ```
### You maight asking what pid is ?
  - Well, It's `process id` each process has a uniqe id
