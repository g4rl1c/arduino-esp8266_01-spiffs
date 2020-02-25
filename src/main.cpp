#include <Arduino.h>
#include <FS.h>

// List all files isnide /data directory

void listFiles()
{
  SPIFFS.begin();
  Serial.println();
  Serial.println("Listing Files");
  String str = "";
  Dir dir = SPIFFS.openDir("/");
  while (dir.next())
  {
    str += "File: ";
    str += dir.fileName();
    str += " - ";
    str += dir.fileSize();
    str += " bytes\r\n";
  }
  Serial.print(str);
  Serial.println();
  Serial.println("End Listing Files");
}

// Create => Crud
void createFile()
{
  // Mount File System. true if mounted and false if not
  if (SPIFFS.begin())
  {
    Serial.println("File System mounted");

    // Set filename variable
    File f = SPIFFS.open("/newf.txt", "r");

    if (f)
    {
      Serial.println("File exist");
    }
    else
    {
      Serial.println("File does not exist");

      // Creating File
      File newF = SPIFFS.open("/newf.txt", "w+");

      //Checking if file was created
      if (!newF)
      {
        Serial.println("New file could not be created");
      }
      else
      {
        Serial.println("New File was created");
        // Printing content inside the new file
        newF.println("I am the content inside the new file");

        Serial.println("New File content was added");

        File newF2 = SPIFFS.open("/newf.txt", "r");

        if (!newF2)
        {
          Serial.println("Could not read file content that was just created");
        }
        else
        {
          String newContent = newF2.readStringUntil('\n');
          Serial.println(newContent);
        }
        newF2.close();
      }

      newF.close();
    }

    f.close();
    Serial.println("File System unmounted");
  }
  else
  {
    Serial.println("File System could not be mounted");
  }
}

// Read => cRud
void readFile()
{
  // Mount File System. true if mounted and false if not
  if (SPIFFS.begin())
  {
    Serial.println("File System mounted");

    // Set filename variable
    File file = SPIFFS.open("/f.txt", "r");

    // Check if the file has any bytes to be read. 0 if empty
    if (file.available())
    {
      // Set Content in a String
      String content = file.readStringUntil('\n');
      // Read content string
      Serial.println(content);
    }
    else
    {
      Serial.println("File does not have any bytes to read");
    }

    file.close();
    Serial.println("File System unmounted");
  }
  else
  {
    Serial.println("File System could not be mounted");
  }
}

//-----------
void renameFile()
{
  // Mount FileSystem
  if (SPIFFS.begin())
  {
    Serial.println("File System succesfully mounted");

    bool rf = SPIFFS.rename("/newf.txt", "/renamedf.txt");

    if (!rf)
    {
      Serial.println("File could not be renamed");
    }
    else
    {
      Serial.println("File was renamed");
    }
  }
  else
  {
    Serial.println("File System could not be mounted");
  }
}

void updateContentFromFile()
{
  // Mount FileSystem
  if (SPIFFS.begin())
  {
    Serial.println("File System succesfully mounted");

    File f = SPIFFS.open("/renamedf.txt", "w+");

    f.print("0123");

    String content = f.readStringUntil('\n');

    Serial.println(content);

    f.close();
  }
  else
  {
    Serial.println("File System could not be mounted");
  }
}
//-----------
// Update => crUd
void updateFile(String option)
{
  if (option == "rename")
  {
    renameFile();
  }
  else
  {
    updateContentFromFile();
  }
}

// Delete => cruD
void deleteFile()
{
  if (SPIFFS.begin())
  {
    Serial.println("File System Mounted");

    if (SPIFFS.exists("/renamedf.txt"))
    {
      SPIFFS.remove("/renamedf.txt");

      Serial.println("File Was Deleted");
    }
    else
    {
      Serial.println("File Does not Exists");
    }
  }
  else
  {
    Serial.println("File System Not Mounted");
  }
}

void setup()
{
  delay(2000);
  Serial.begin(115200);
  Serial.println();

  // createFile();
  // readFile();
  // updateFile("update"); // rename or update as parameter
  deleteFile();
  listFiles();
}

void loop()
{
  // nothing to do for now, this is just a simple test
}