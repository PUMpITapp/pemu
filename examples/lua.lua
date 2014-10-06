gfx = require "gfx"
gfx.screen:clear({255,0,0})
gfx.update()

----gfx.screen:copyfrom(a, {x=0, y=0, w=100, h=100}, {x=200, y=200})
----gfx.update()
img = gfx.loadjpeg("ours.jpg")
gfx.screen:copyfrom(img, nil, {x=20, y=20})
gfx.update()

function onKey(key,state)
	print(key)

	if(key == 'green') then
	gfx.screen:clear({0,0,255})
	gfx.update()
	--continue()
	end
end
----print(gfx.gfx_get_memory_use())
----a:copyfrom(gfx.screen, {x=450, y=450, w=200, h=200}, {x=0, y=0})
----gfx.update()
