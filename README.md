# Arduino ESP8266 01 SPIFFS

SPIFFS on a esp8266 01 1M using arduino framework, PlatformIO on VS Code

## Uploading to File System

To upload files into the File System, it needs to be created a data (data is the default dir_path, if you need another oe, you will need to set it up at platformio.ini).

Use

```
pio run -t uploadfs
```

## CRUD

This code shows how to do a CRUD using SPIFFS library

## Functions

> **listFiles()**

This function opens the directory given and display all files inside given directory

### Create

> **createFile()**

This function creates a file from given directory

### Read

> **readFile()**

This function creates a file from given directory

### Update

> **updateFile(String option)**

This function updates a file from given directory and it receives a **_String_**. as a parameter.

This function calls 2 diffeent function depending on the parameter given

If **_rename_** is given it will call the **renameFile()** function, which will just rename the file name. If you give a different parameter (I used the word **update**) it will call the **updateContentFromFile()** function, which will remove all the content inside the file and save a new content into it

### Delete

> **deleteFile()**

This function deletes (remove) a file from given directory

#### Note

This code was built for references only. It can be improved, and if anyone wants to help, let me know
