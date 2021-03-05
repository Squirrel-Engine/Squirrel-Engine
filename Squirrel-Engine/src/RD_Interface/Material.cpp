#include "Material.h"
#include <iostream>

Material::Material()
{

}

void Material::setup()
{
	s_Texture texture;
	Texture* tex = new Texture("../../Squirrel-Engine/res/textures/default/color.png"); // This gonna change, after we load all default textures at once at the 
	texture.id = tex->getID();															// beginning then we'll assign same texture id to avoid multiple load
	texture.type = "texture_diffuse";
	texture.path = "color.png";
	textures.push_back(texture);
}

void Material::setInt(int value)
{
}

void Material::setFloat(float value)
{
}

void Material::setColor(glm::vec4 color)
{
	this->color = color;
}

void Material::setTexture(string typeName, const std::string& path)
{
	s_Texture texture;
	Texture* tex = new Texture(path); 
	texture.id = tex->getID();
	texture.type = typeName;
	//texture.path = tex->getPath();
	textures.push_back(texture);
}
