/**
 * @module root
 */
#include "game.h"

using namespace godot;

GDGame::GDGame() = default;;

GDGame::~GDGame() = default;;

void GDGame::_register_methods() {
	register_method("_process", &GDGame::_process);
}

void GDGame::_init() {
	// TODO
}

void GDGame::_process(float delta) {
	// TODO
}
