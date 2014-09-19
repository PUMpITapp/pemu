Zenterio Lua API

This document describes the functions available to Lua code executed
by the Zenterio OS LuaEngine application.

After the initial evaluation of the code, the execution is completely
event-driven. The following events exist:
* onKey(key, state)
  RCU key input. The following keys are defined (as strings):
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ok, up, down, left, right, red,
    green, yellow, blue, white, info, menu, guide, opt, help, star,
    multi, exit, pause, toggle_tv_radio, record, play, stop,
    fast_forward, rewind, skip_forward, skip_reverse, jump_to_end,
    jump_to_beginning, toggle_pause_play, vod, backspace, hash, back,
    ttx, record_list, play_list, mute
  State is either 'down', 'repeat' or 'up'. A keypress generates one
  'down', zero or more 'repeat' and exactly one 'up'.

* Timer event
  User-specified function, taking the timer object as argument.

* onStart()
  Called once after loading the script into a new environment at start


## surface data types ##
An area (pixmap) in graphics memory. Format is 32-bit RGBA.

surface:clear([color, [rectangle]])
  Fills the surface with a solid color, using hardware acceleration.
  Surface transparency is replaced by the transparency value of
  <color>.
  Default color is {0, 0, 0, 0}, that is black and completely transparent.
  Default rectangle is the whole surface. Parts outside the rectangle
  are not affected.

surface:fill(color, [rectangle])
  Blends the surface with a solid color, weighing alpha values
  (SRCOVER). Uses hardware acceleration.
  Default rectangle is the whole surface. Parts outside the rectangle
  are not affected.

surface:copyfrom(src_surface, src_rectangle, [dest_rectangle, [blend_option]])
  Copy pixels from one surface to another, using hardware
  acceleration. Parts or all of <src_surface> can be copied.

  Scaling is done if dest_rectangle is of different size than
  src_rectangle. Areas outside of source or destination surfaces are
  (will be) clipped.

  If <src_rectangle> is nil, the whole <src_surface> is used.

  If <dest_rectangle> is nil or omitted, x=0, y=0 are assumed and
  width and height are taken from <src_rectangle>. If <dest_rectangle>
  doesn't specify width or height, these values are also taken from
  <src_rectangle>.

  If <blend_option> is true, copying is blended using the alpha
  information in <src_surface>. If false, the alpha channel is
  replaced by the values in <src_surface>.
  Default is false.

surface:get_width()
  Returns the pixel width (X axis) of the surface

surface:get_height()
  Returns the pixel height (Y axis) of the surface

surface:get_pixel(x, y)
  Returns the color value at position <x>, <y>, starting with index (0, 0).
  Mostly for testing, not optimized for speed

surface:set_pixel(x, y, color)
  Sets the pixel at position <x>, <y> to <color>.
  Mostly for testing, not optimized for speed

surface:premultiply()
  Changes the surface pixel components by multiplying the alpha
  channel into the color channels. This prepares some images for
  blending with transparency.

surface:destroy()

  Frees the graphics memory used by this surface. The same is
  eventually done automatically by Lua garbage collection for
  unreferenced surfaces but doing it by hand guarantees the memory is
  returned at once.
  The surface can not be used again after this operation.

color
  A Lua table of the color and alpha components, in range 0-255.
  Valid forms are

  -- Specify R, G, B. Alpha is 255 (opaque):
  {0, 0, 0}

  -- Specify R, G, B, A:
  {0, 0, 0, 0}

  -- Specify components by short name. Omitted components default to
  -- 0. At least one component must be specified:
  {r=0, g=0, b=0, a=0} 

  -- Specify components by long name. Omitted components default to
  -- 0. At least one component must be specified.
  {red=0, green=0, blue=0, alpha=0}

rectangle
  A Lua table specifying x, y, width and height
  In some cases, width and height are optional.
  Negative width or height are not allowed.
  At the moment, negative x or y are not allowed either.
  Valid forms are:
  {x=0, y=0, w=0, h=0}
  {x=0, y=0, width=0, height=0}

## timer data type ##
  A recurring timer that triggers a configurable callback at a
  specific interval.

timer:set_interval()
  Changes the interval

timer:stop()
  No more callbacks are generated, even if a timer timeout already
  happened and was waiting for dispatching.

timer:start()
  The timer starts generating callbacks at the prescribed interval, if
  previously stopped.


## sys module ##

sys.new_timer(interval_millisec, callback)
  Creates and starts a timer that calls <callback> every <interval_millisec>.
  <callback> can be a function or a string.
  If a string, the global variable of this name will be fetched each
  time the timer triggers and that variable will be called, assuming
  it is a function. In this way, callbacks can be replaced in real-time.

  The callback function is called with signature:
  callback(timer)
  where <timer> is the timer object that triggered the event

sys.time()
  Returns the time since the system started, in seconds and fractions
  of seconds. Useful to measure lengths of time.

sys.stop()
  Terminates the execution of the script. The rest of the currently
  executing code will be run, but all timers are stopped and the
  current script environment will never be called again.


## gfx module ##

gfx.set_auto_update(bool)
  If set to true, any change to gfx.screen immediately triggers
  gfx.update() to make the change visible. This slows the system if
  the screen is updated in multiple steps but is useful for
  interactive development.

gfx.new_surface(width, height)
  Creates and returns a new 32-bit RGBA graphics surface of chosen
  dimensions. The surface pixels are not initialized; clear() or
  copyfrom() should be used for this.
  <width> and <height> must be positive integers and each less than 10000.
  An error is raised if enough graphics memory cannot be allocated.

gfx.get_memory_use()
  Returns the number of bytes of graphics memory the application
  currently uses. Each allocated pixel uses 4 bytes since all surfaces
  are 32-bit. A limit of gfx.get_memory_limit() is enforced.

gfx.screen or screen
  The surface that shows up on the screen when gfx.update() is called.
  Calling gfx.set_auto_update(true) makes the screen update
  automatically when gfx.screen is changed (for development; too slow
  for animations)

gfx.get_memory_limit()
  Returns the maximum bytes of graphics memory the application is
  allowed to use.

gfx.update()
  Makes any pending changes to gfx.screen visible.

gfx.loadpng(path)
  Loads the PNG image at <path> into a new surface that is
  returned. The image is always translated to 32-bit
  RGBA. Transparency is preserved. A call to surface:premultiply()
  might be necessary for transparency to work.
  An error is raised if not enough graphics memory can be allocated.

gfx.loadjpeg(path)
  Loads the JPEG image at <path> into a new surface that is returned.
  The image is always translated to 32-bit RGBA. All pixels will be
  opaque since JPEG does not support transparency.  
  An error is raised if not enough graphics memory can be allocated.
