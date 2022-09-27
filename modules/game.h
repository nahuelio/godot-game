/**
 * Example integrating Godot GDNative into the project
 * @module root
 *
 * @see https://docs.godotengine.org/en/stable/tutorials/scripting/gdnative/gdnative_cpp_example.html
 */

#ifndef GODOT_GAME_GAME_H
#define GODOT_GAME_GAME_H

#include <core/Godot.hpp>
#include <gen/Sprite.hpp>

namespace godot {
	class GDGame : public Sprite {
		GODOT_CLASS(GDGame, Sprite)

	public:
		static void _register_methods();

		GDGame();
		~GDGame();

		void _init();

		void _process(float delta);
	};
}

#endif //GODOT_GAME_GAME_H
