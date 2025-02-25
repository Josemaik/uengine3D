#version 330

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout (location = 0) in vec3 vpos;
layout (location = 1) in vec3 vnormal;
layout (location = 2) in vec2 vtex;
layout (location = 3) in vec4 vcolor;

out vec3 FragPos;
out vec3 Normal;
out vec2 ftex;
out vec4 fcolor;
out vec3 fnormal;
out vec4 FragPosLightSpace;

void main(){
	FragPos= vec3(model* vec4(vpos, 1.0));
	gl_Position = projection*view*vec4(FragPos, 1);
	ftex = vtex ;
	fcolor = vcolor;
	Normal = mat3(transpose(inverse(model))) * vnormal; 
}