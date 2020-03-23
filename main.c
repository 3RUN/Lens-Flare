
#include <acknex.h>
#include <default.c>
#include <windows.h>

#define PRAGMA_POINTER

#define PRAGMA_PATH "resources"

#define TRACE_FLAGS (IGNORE_ME + IGNORE_PASSABLE + IGNORE_PASSENTS + IGNORE_MAPS + IGNORE_SPRITES + IGNORE_CONTENT)
#define MOVE_FLAGS (IGNORE_ME + IGNORE_PASSABLE + IGNORE_PASSENTS + IGNORE_MAPS + IGNORE_SPRITES + IGNORE_CONTENT)

#define OBJ_ID skill50
#define OBJ_STRUCT skill51
#define OBJ_TYPE skill52
#define TYPE_NONE 0
#define TYPE_LIGHT 1

#include "lens_flare.h"

ENTITY *sky_cube_ent = 
{
	type = "skycube+6.tga";
	flags2 = SKY | CUBE | SHOW;
	layer = 2;
}

void light_event()
{
	if(event_type == EVENT_CLICK)
	{
		my->emask &= ~ENABLE_CLICK;
		ptr_remove(my);
	}
	
	if(event_type == EVENT_FRAME)
	{
		my->x = my->skill1 + fsin(total_ticks * 8, 64);
		my->y = my->skill2 + fcos(total_ticks * 8, 64);
		
		update_lens_flare(my);
	}
}

action light_bulb()
{
	set(my, UNLIT | BRIGHT | LIGHT);
	my->ambient = 100;
	vec_set(&my->blue, vector(128, 128, 128));
	
	lens_flare_register(my, nullvector);
	
	my->emask |= ENABLE_CLICK | ENABLE_FRAME;
	my->event = light_event;
	
	vec_set(&my->skill1, &my->x);
}

void mouse_lock()
{
	static var autolock_mouse_locked = false;
	if (!autolock_mouse_locked && window_focus)
	{
		autolock_mouse_locked = true;
		RECT rect;
		GetClientRect(hWnd, &rect);
		ClientToScreen(hWnd, &rect);
		ClientToScreen(hWnd, &rect.right);
		SetCursorPos(rect.left, rect.top);
		ClipCursor(&rect);
	}
	if (autolock_mouse_locked && !window_focus)
	{
		autolock_mouse_locked = false;
		ClipCursor(NULL);
	}
}

void on_exit_event()
{
}

void on_ent_remove_event(ENTITY *ent)
{
	if(ent->OBJ_TYPE == TYPE_LIGHT && ent->OBJ_STRUCT != 0)
	{
		remove_lens_flare(ent);
	}
}

void on_frame_event()
{
	lens_flare_sun_update();
}

void main()
{
	on_exit = on_exit_event;
	on_ent_remove = on_ent_remove_event;
	on_frame = on_frame_event;
	
	tex_cycles = 5;
	warn_level = 6;
	fps_max = 60;
	
	mouse_pointer = 2;
	mouse_mode = 4;
	
	video_mode = 10;
	
	level_load("scene.wmb");
	wait(3);
	
	camera->arc = 90;
	camera->clip_far = 2000;
	camera->clip_near = 0.1;
	
	camera->fog_start = 512;
	camera->fog_end = camera->clip_far * 0.9;
	sun_angle.roll = camera->fog_end * 0.8;
	
	fog_color = 4;
	vec_set(&d3d_fogcolor4.blue, vector(128, 128, 128));
	vec_set(&sky_color.blue, &d3d_fogcolor4.blue);
	
	vec_set(&camera->x, vector(215, -241, 93));
	vec_set(&camera->pan, vector(139, -15, 0));
	
	sun_light = 100;
	
	vec_set(&sun_color, vector(128, 128, 128));
	vec_set(&ambient_color, vector(0, 0, 0));
	
	sun_lens_flare_create_all();
	
	VECTOR force, speed, dist;
	ANGLE aforce, aspeed;
	
	vec_fill(&force, 0);
	vec_fill(&speed, 0);
	vec_fill(&dist, 0);
	
	vec_fill(&aforce, 0);
	vec_fill(&aspeed, 0);
	
	while(!key_esc)
	{
		sun_angle.pan += 5 * (key_cul - key_cur) * time_step; 
		sun_angle.tilt += 5 * (key_cuu - key_cud) * time_step; 
		
		aforce.pan = -5 * (mouse_right * mouse_force.x);
		aforce.tilt = 5 * (mouse_right * mouse_force.y);
		aforce.roll = 0;
		vec_add(&camera->pan, vec_accelerate(&dist, &aspeed, &aforce, 0.8));
		
		force.x = 7 * (key_w - key_s);
		force.y = 3 * (key_a - key_d);
		force.z = 3 * (key_q - key_e);
		vec_accelerate(&dist, &speed, &force, 0.5);
		vec_add(&camera->x, vec_rotate(&dist, &camera->pan));
		
		mouse_lock();
		wait(1);
	}
}