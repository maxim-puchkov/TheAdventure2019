# **!** See below how to run your code only.
## You should **implement tests** and **compile your code**
Now you don't need to modify existing game files. Install your class build scheme. Write some tests to make sure
your dependecies set up correctly. Show how your code works and    ```cout``` your outputs. 



# Keep current libraries maintained and push your *working* code
## Always be up to date: you can clone this branch

    git clone -b libs https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019.git
`



## Build and test your code

1. Run CMake with the path to the source.

    ```cmake ../adventure2019/```

2. Each class has a build scheme where you can write code to perform tests.

Available schemes:  ``` sworld, sgame, susers, saccs```

3. Run make install <scheme> inside the build directory:


    ```make install sworld```


4. Your files have to compile. You can run your executable code with:

    ```bin/sworld```



## Configure your builds

1. Run CMake with the path to the source and set value of:

```CMAKE_BUILD_TYPE=[DEBUG|RELEASE]```

2. Strict RELEASE build can be enabled by setting -DCMAKE_BUILD_TYPE when running CMake.

```cmake -DCMAKE_BUILD_TYPE=RELEASE ../adventure2019```


## Default build with CMake

1. Run CMake with the path to the source.

```cmake ../adventure2019/
```
2. Run make inside the build directory:

```make```


*Old README.md moved to **lib/network***
*https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/tree/master/lib/network*

