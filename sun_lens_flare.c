
// create lens flare for the sun with the given parameters
void sun_lens_flare_init(STRING *file_, var layer_, var size_x_, var size_y_, var size_z_, var dist_, var alpha_, VECTOR *offset_)
{
	sun_lens.flare[total_sun_lens_flare].ent = ent_createlayer(file_, 0, layer_);
	set(sun_lens.flare[total_sun_lens_flare].ent, BRIGHT | TRANSLUCENT | LIGHT);
	
	sun_lens.flare[total_sun_lens_flare].ent->alpha = 0;
	sun_lens.flare[total_sun_lens_flare].ent->ambient = 100;
	sun_lens.flare[total_sun_lens_flare].ent->albedo = -100;
	sun_lens.flare[total_sun_lens_flare].ent->scale_x = size_x_;
	sun_lens.flare[total_sun_lens_flare].ent->scale_y = size_y_;
	sun_lens.flare[total_sun_lens_flare].ent->scale_z = size_z_;
	
	sun_lens.flare[total_sun_lens_flare].pivot_dist = dist_;
	sun_lens.flare[total_sun_lens_flare].alpha = alpha_;
	vec_set(&sun_lens.flare[total_sun_lens_flare].offset, offset_);
	total_sun_lens_flare++;
}

// create all sun lens flare
void sun_lens_flare_create_all()
{
	// setup settings
	sun_lens.temp_alpha[0] = MAX_SUN_ALPHA;
	sun_lens.temp_alpha[1] = 100;
	sun_lens.temp_alpha[2] = 100;
	sun_lens.center_alpha[0] = 20;
	
	// scale factor for world sun and aura sprites
	var scale_factor = 1 * (camera->clip_far * 1 / 100) / 100;
	
	// create sun
	sun_lens.sun_ent = ent_create(sun_lens_b_tga, nullvector, NULL);
	set(sun_lens.sun_ent, PASSABLE | BRIGHT | TRANSLUCENT | NOFOG | FLAG8);
	sun_lens.sun_ent->ambient = 100;
	sun_lens.sun_ent->albedo = -100;
	sun_lens.sun_ent->alpha = 0;
	sun_lens.sun_ent->scale_x = 3 * scale_factor;
	sun_lens.sun_ent->scale_y = 3 * scale_factor;
	
	// create aura effect for sun
	sun_lens.aura_ent = ent_create(sun_lens_b_tga, nullvector, NULL);
	set(sun_lens.aura_ent, PASSABLE | BRIGHT | TRANSLUCENT | NOFOG);
	sun_lens.aura_ent->ambient = 100;
	sun_lens.aura_ent->albedo = -100;
	sun_lens.aura_ent->alpha = 0;
	sun_lens.aura_ent->scale_x = 16 * scale_factor;
	sun_lens.aura_ent->scale_y = 12 * scale_factor;
	
	// create all lens flare
	sun_lens_flare_init(sun_lens_a_tga, 1, 2, 2, 1, 1.0, 40.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_a_tga, 1, 2.3, 2.3, 1, 1.0, 40.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_c_tga, 10, 13, 13, 1, 1.0, 100.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_d_tga, 2, 1, 1, 1, 1, 3.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_e_tga, 2, 1, 1, 1, 1, 5.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_f_tga, 3, 1, 1, 1, 1, 60.0, vector(0.5, 0, 0));
	sun_lens_flare_init(sun_lens_f_tga, 3, 1, 1, 1, 1, 60.0, vector(-0.5, 0, 0));
	sun_lens_flare_init(sun_lens_f_tga, 3, 2, 0.7, 1, 1, 40.0, vector(1.1, 0, 0));
	sun_lens_flare_init(sun_lens_f_tga, 3, 2, 0.7, 1, 1, 40.0, vector(-1.1, 0, 0));
	sun_lens_flare_init(sun_lens_g_tga, 1, 1, 1, 1, 1, 8.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_h_tga, 1, 1, 1, 1, 1.08, 16.0, vector(-1.1, -1.1, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 1.2, 1.2, 1, 1.2, 12.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 3.6, 3.6, 1, 1.35, 6.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 0.6, 0.6, 1, 0.76, 15.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 0.2, 0.2, 1, 0.55, 45.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 0.8, 0.8, 1, 0.33, 15.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 0.1, 0.1, 1, 0.2, 45.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 1, 2, 2, 1, 0.05, 15.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 2, 1, 1, 1, 0.01, 11.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 2, 2, 2, 1, -0.5, 9.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_i_tga, 3, 7, 7, 1, -1, 3.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_mdl, 4, 0, 25, 25, -1.35, 5.0, vector(0, 0, 0));
	sun_lens_flare_init(sun_lens_mdl, 3, 0, 3, 3, -0.85, 7.5, vector(0, 0, 0));
}

// custom sun position
// faced some troubles with the native sun_pos (clipping, fog etc)
void sun_lens_flare_pos_update()
{
	vec_set(&sun_pos3d, vector(sun_angle.roll, 0, 0));
	vec_rotate(&sun_pos3d, vector(sun_angle.pan, sun_angle.tilt, 0));
	vec_add(&sun_pos3d, &camera->x);
}

// check if sun is visible from the camera position
// true - if visible, otherwise - false
var is_sun_visible()
{
	var is_visible = true;
	c_trace(&camera->x, &sun_pos3d, TRACE_FLAGS);
	if(HIT_TARGET)
	{
		is_visible = false;
	}
	return is_visible;
}

// place given lens flare with offset at the given position
void sun_lens_flare_place(LENS_FLARE *flare, VECTOR *pos_)
{
	vec_set(&flare->world_pos, pos_);
	set(flare->ent, TRANSLUCENT | BRIGHT);
	flare->ent->flags2 |= SHOW;
	
	flare->ent->ambient = 100;
	flare->ent->albedo = -100;
	
	flare->ent->x = flare->world_pos.x * flare->pivot_dist + 0.5 * screen_size.x + (flare->world_pos.x * flare->offset.x);
	flare->ent->y = flare->world_pos.y * flare->pivot_dist + 0.5 * screen_size.y + (flare->world_pos.y * flare->offset.y);
	flare->ent->z = 750;
	rel_for_screen(&flare->ent->x, camera);
}

// update all sun lens flare
void lens_flare_sun_update()
{
	sun_lens_flare_pos_update();
	
	// terminate if nothing was created yet
	if(!sun_lens.sun_ent){ return; }
	
	// need to get sun lens flare to work ?
	if(sun_lens_flare_active == true)
	{
		// place and rotate sun + aura to camera
		VECTOR temp_sun;
		vec_set(&temp_sun, vector(16, 0, 0));
		
		ANGLE temp_sun_dir;
		vec_to_angle(&temp_sun_dir, vec_diff(NULL, &camera->x, &sun_pos3d));
		vec_rotate(&temp_sun, &temp_sun_dir);
		vec_add(&temp_sun, &sun_pos3d);

		vec_set(&sun_lens.sun_ent->x, &sun_pos3d);
		vec_set(&sun_lens.aura_ent->x, &sun_pos3d);
		vec_to_angle(&sun_lens.sun_ent->pan, vec_diff(NULL, &sun_lens.sun_ent->x, &camera->x));
		vec_to_angle(&sun_lens.aura_ent->pan, vec_diff(NULL, &sun_lens.aura_ent->x, &camera->x));
		
		// adjust alpha values for sun and it's aura
		sun_lens.sun_ent->alpha = (MAX_SUN_ALPHA - (sun_lens.temp_alpha[0] / 2)) + random((2 / 100) * sun_lens.temp_alpha[0]);
		sun_lens.aura_ent->alpha = (10.0 / 100.0 * (sun_lens.temp_alpha[0] + 80)) + random((2.0 / 100.0) * sun_lens.temp_alpha[0]);
		sun_lens.temp_alpha[0] = maxv(0, sun_lens.temp_alpha[0]);
		
		// check if sun is visible or not
		var is_visible = is_sun_visible();
		
		VECTOR temp_pos;
		vec_set(&temp_pos, &sun_pos3d);
		
		// sun not on screen and not visible ?
		if(vec_to_screen(&temp_pos, camera) == 0 || is_visible == false)
		{
			// fade away
			if(sun_lens.temp_alpha[0] > 0)
			{
				sun_lens.temp_alpha[0] -= 40 * time_step;
				set(sun_lens.sun_ent, FLAG8);
			}
			sun_lens.temp_alpha[1] = 100;
			sun_lens.temp_alpha[2] = 100;
			
			// adjust alpha for all lens flares
			// so they fade away
			int i = 0;
			for(i = 0; i < total_sun_lens_flare; i++)
			{
				var alpha_ = sun_lens.flare[i].alpha;
				sun_lens.flare[i].ent->alpha = (alpha_ / 100.0 * sun_lens.temp_alpha[0]) + random((0.02) * sun_lens.temp_alpha[0]);
			}
			
			sun_lens.flare[0].ent->roll += 0.03 * time_step;
			sun_lens.flare[1].ent->roll -= 0.06 * time_step;
		}
		else // visible ?
		{
			temp_pos.x -= 0.5 * screen_size.x;
			temp_pos.y -= 0.5 * screen_size.y;
			
			int i = 0;
			for(i = 0; i < total_sun_lens_flare; i++)
			{
				// fade lens flares
				var alpha_ = sun_lens.flare[i].alpha * SUN_ALPHA_FACTOR;
				sun_lens.flare[i].ent->alpha = (alpha_ / 100.0 * sun_lens.temp_alpha[0]) + random((0.02) * sun_lens.temp_alpha[0]);
				
				// place them correctly on the screen
				sun_lens_flare_place(&sun_lens.flare[i], &temp_pos);
			}
			
			if(temp_pos.x > 696){ sun_lens.temp_alpha[1] = (796 - temp_pos.x); }			
			if(temp_pos.x < -696){ sun_lens.temp_alpha[1] = abs((-796 - temp_pos.x)); }			
			if(temp_pos.y > 495){ sun_lens.temp_alpha[2] = (595 - temp_pos.y); }			
			if(temp_pos.y < -495){ sun_lens.temp_alpha[2] = abs((-595 - temp_pos.y)); }			
			if(temp_pos.x > 696 || temp_pos.x < -696 || temp_pos.y > 495 || temp_pos.y < -495)
			{
				if(sun_lens.temp_alpha[1] < sun_lens.temp_alpha[2]){ sun_lens.temp_alpha[0] = sun_lens.temp_alpha[1]; }
				if(sun_lens.temp_alpha[2] < sun_lens.temp_alpha[1]){ sun_lens.temp_alpha[0] = sun_lens.temp_alpha[2]; }
			}
			
			sun_lens.flare[0].ent->roll += 0.03 * time_step;
			sun_lens.flare[1].ent->roll -= 0.06 * time_step;
			sun_lens.flare[2].ent->alpha = (sun_lens.center_alpha[0] / 100.0) * sun_lens.temp_alpha[0];
			
			sun_lens.center_alpha[1] = abs(temp_pos.x);
			sun_lens.center_alpha[2] = abs(temp_pos.y);
			
			if(sun_lens.center_alpha[1] > sun_lens.center_alpha[2]){ sun_lens.center_alpha[0] = (100 - sun_lens.center_alpha[1]); }
			if(sun_lens.center_alpha[2] > sun_lens.center_alpha[1]){ sun_lens.center_alpha[0] = (100 - sun_lens.center_alpha[2]); }
			
			sun_lens.flare[3].ent->scale_x = abs(temp_pos.x / 60.0);
			sun_lens.flare[3].ent->scale_y = abs(temp_pos.x / 300.0);
			sun_lens.flare[4].ent->scale_x = abs(temp_pos.x / 200.0);
			sun_lens.flare[4].ent->scale_y = abs(temp_pos.x / 150.0);
			sun_lens.flare[5].ent->scale_x = abs(temp_pos.x / 700.0);
			sun_lens.flare[5].ent->scale_y = abs(temp_pos.x / 350.0);
			sun_lens.flare[6].ent->scale_x = abs(temp_pos.x / 700.0);
			sun_lens.flare[6].ent->scale_y = abs(temp_pos.x / 350.0);
			sun_lens.flare[7].ent->scale_x = abs(temp_pos.x / 100.0);
			sun_lens.flare[8].ent->scale_x = abs(temp_pos.x / 100.0);
			
			sun_lens.temp_var[0] = abs(temp_pos.x) - (abs(temp_pos.x) - abs(temp_pos.x));
			sun_lens.temp_var[1] = abs(temp_pos.y) - (abs(temp_pos.y) - abs(temp_pos.y));
			sun_lens.scale = sqrt(sun_lens.temp_var[0] * sun_lens.temp_var[0] + sun_lens.temp_var[1] * sun_lens.temp_var[1]);   
			
			sun_lens.flare[9].ent->scale_x = sun_lens.scale / 100.0;
			sun_lens.flare[9].ent->scale_y = sun_lens.scale / 100.0;
			sun_lens.flare[10].ent->scale_x = sun_lens.scale / 250.0;
			sun_lens.flare[10].ent->scale_y = sun_lens.scale / 250.0;
			
			sun_lens.diff = camera->pan - camera->tilt;
			sun_lens.flare[9].ent->roll = sun_lens.diff - 60.0;
			
			sun_lens.temp_var2[0] = (temp_pos.x - temp_pos.x);
			sun_lens.temp_var2[1] = (temp_pos.y - temp_pos.y);
			
			ANGLE angle;
			vec_to_angle(&angle, vec_diff(NULL, &temp_pos, vector(sun_lens.temp_var2[0], sun_lens.temp_var2[1], 0)));
			
			sun_lens.flare[10].ent->roll = angle.pan - (angle.pan * 2) - 90;
			
			// shift textures for last two lens flare (models)
			sun_lens.flare[21].ent->v += 0.4 * time_step;
			sun_lens.flare[21].ent->u -= 0.1 * time_step;
			sun_lens.flare[22].ent->v += 0.4 * time_step;
			sun_lens.flare[22].ent->u -= 0.1 * time_step;
			
			// adjust colors for specific lens flare
			vec_set(&sun_lens.flare[11].ent->blue, vector(10, 200, 220));
			vec_set(&sun_lens.flare[12].ent->blue, vector(50, 220, 250));
			vec_set(&sun_lens.flare[13].ent->blue, vector(0, 180, 25));
			vec_set(&sun_lens.flare[14].ent->blue, vector(100, 20, 80));
			vec_set(&sun_lens.flare[15].ent->blue, vector(200, 35, 140));
			vec_set(&sun_lens.flare[16].ent->blue, vector(80, 5, 50));
			vec_set(&sun_lens.flare[17].ent->blue, vector(120, 60, 10));
			vec_set(&sun_lens.flare[18].ent->blue, vector(200, 20, 40));
			vec_set(&sun_lens.flare[19].ent->blue, vector(200, 20, 40));
			vec_set(&sun_lens.flare[20].ent->blue, vector(180, 250, 45));
			
			// fade in
			if(sun_lens.temp_alpha[0] < MAX_SUN_ALPHA && is(sun_lens.sun_ent, FLAG8))
			{
				sun_lens.temp_alpha[0] += 40 * time_step;
				if(sun_lens.temp_alpha[0] > (MAX_SUN_ALPHA - 1))
				{
					sun_lens.temp_alpha[0] = MAX_SUN_ALPHA;
					reset(sun_lens.sun_ent, FLAG8);
				}
			}
		}
	}
	else // disable lens flare for sun
	{
		// hide sun and it's aura	
		sun_lens.sun_ent->alpha = 0;
		sun_lens.aura_ent->alpha = 0;
		
		// hide all lens flares
		int i = 0;
		for(i = 0; i < total_sun_lens_flare; i++)
		{
			sun_lens.flare[i].ent->alpha = 0;
		}
		
		// reset all other stuff
		set(sun_lens.sun_ent, FLAG8);
		sun_lens.temp_alpha[0] = 0;
		sun_lens.temp_alpha[1] = 0;
		sun_lens.temp_alpha[2] = 0;
	}
}