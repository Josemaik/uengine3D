#version 330

uniform sampler2D texSampler;

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;
};

struct DirLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec4 fcolor;
in vec2 ftex;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform Material material;

uniform bool drawTexture;

out vec4 FragColor;

//vec3 CalcDirLight(DirLightlight, vec3 normal, vec3 viewDir)
//{
// vec3 lightDir= normalize(-light.direction);
// // diffuse shading
// float diff = max(dot(normal, lightDir), 0.0);
// // specular shading
// vec3 reflectDir= reflect(-lightDir, normal);
// floatspec= pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//
// // combine results
// vec3 ambient  = light.ambient* material.ambientColor;
// vec3 diffuse= light.diffuse* diff*  material.diffuseColor;
// vec3 specular= light.specular* spec*  material.specularColor;
// if(useTexture== 0)
// {
//	 ambient  = ambient  * vec3(texture(material.diffuse, TexCoords));
//	 diffuse  = diffuse  * vec3(texture(material.diffuse, TexCoords));
//	 specular = specular* vec3(texture(material.specular, TexCoords));
// }
//
// return(ambient+ diffuse+ specular);
//}

void main() {
	if(drawTexture)
	{
		//vec3 norm = normalize(Normal);
		//vec3 viewDir= normalize(viewPos-FragPos);
		//vec3 result= CalcDirLight(dirLight, norm, viewDir);
		//FragColor= vec4(result, 1.0);
		gl_FragColor = texture2D( texSampler , ftex );
	}
	else
	{
		gl_FragColor = fcolor;
	}
};

