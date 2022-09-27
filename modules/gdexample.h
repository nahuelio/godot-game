/**
 * Example integrating Godot GDNative into the project
 * @module root
 *
 * @see https://docs.godotengine.org/en/stable/tutorials/scripting/gdnative/gdnative_cpp_example.html
 */

#ifndef GODOT_GAME_GDEXAMPLE_H
#define GODOT_GAME_GDEXAMPLE_H

#include <core/Godot.hpp>
#include <gen/Sprite.hpp>

namespace godot {
	class GDExample : public Sprite {
		GODOT_CLASS(GDExample, Sprite)

	public:
		static void _register_methods();

		GDExample();
		~GDExample();

		void _init();

		void _process(float delta);
	};
}

#endif //GODOT_GAME_GDEXAMPLE_H
