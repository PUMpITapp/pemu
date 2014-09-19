# Usage of LuaEngine #

LuaEngine is the Zenterio OS application that executes Lua scripts for
advertisements. The application maintains a Lua environment,
containing the complete code and state of the current script. Active
timers and key input is sent to this environment.

## Control ##

Login to the STB using telnet. You will get a root shell terminal. Run
"ZacCmdClient" to enter the command mode for applications.
The commands available for LuaEngine are:

startapp LuaEngine LuaEngine [script]
  Starts LuaEngine. Optionally give a script to run.
  The execution will be sandboxed to the directory of the script.

sendcmd LuaEngine exit
sendcmd LuaEngine quit
  Exits LuaEngine altogether.

sendcmd LuaEngine stop
  Stops any timers and clears the Lua environment.
  Equivalent to Lua sys.stop()
  Requires LuaEngine to already be running.

sendcmd LuaEngine run <filename>
  Clears the current environment and loads and runs <filename>. Runs
  onStart().
  The execution will be sandboxed to the directory of the script.
  Requires LuaEngine to already be running.

sendcmd LuaEngine addfile <filename>
  Loads <filename> into the current environment without stopping or
  clearing the environment.
  Requires LuaEngine to already be running.  Doesn't change the script
  sandbox (paths will still be relative to existing sandbox).

sendcmd LuaEngine eval <expression>
  Evaluate a Lua expression in the current environment.
  Requires LuaEngine to already be running.  Doesn't change the script
  sandbox (paths will still be relative to existing sandbox).


## Telnet ##

For development, the application listens for a telnet connection on
port 10001 when running. The telnet session presents an interactive
Lua prompt (REPL) in the environment of the current script. Globals
can be inspected and changed, and the full API available to Lua
scripts can be used.

The line "quit" exits the telnet session without affecting the
run-time environment.

