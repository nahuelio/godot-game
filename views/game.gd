class_name Game, "res://icon.png"
extends Node

func _init():
	print(self.get_viewport())

func _ready():
	print("Hello World")
	print(self.name)
