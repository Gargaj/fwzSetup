/*

  SETUP DIALOG CODE FOR DUMMIES
  
  by Gargaj / Conspiracy ^ �mla�t Design

  LICENSE: Feel free to use this code without
    any obligation, just make the end product good.

*/

#include "fwzSetup.h"

#ifdef _CONSOLE
int main()
#else
INT WINAPI WinMain( HINSTANCE hInstance,
  HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow )
#endif
{
  fwzSettings setup;

  // You HAVE to initialize this before trying to open a dialog!  
#ifdef _CONSOLE
  setup.hInstance = GetModuleHandle(NULL);
#else
  setup.hInstance = hInstance;
#endif

  // These are just some default settings I found convenient to work with.
  // If you modify them, the setupbox will initialize accordingly.
  setup.scrBPP = 32;
  setup.nVsync = 1;
  setup.nMultisample = 0;
#ifdef _DEBUG
  // It's a fairly good idea not to set always-on-top when
  // you're debugging, since otherwise it gets stuck
  // on top your debug window.
  setup.nAlwaysOnTop = 0;
  setup.scrWidth = 640;
  setup.scrHeight = 480;
  setup.nWindowed = 1;
#else
  setup.nAlwaysOnTop = 1;
  setup.scrWidth = 800;
  setup.scrHeight = 600;
  setup.nWindowed = 0;
  if (!OpenSetupDialog(&setup)) return -1;
#endif

  // And this is where your code can kick in.
  // Note that the setupbox doesn't get called
  // when you compile DEBUG, since you don't really
  // need it anyway.
}