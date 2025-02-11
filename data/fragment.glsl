uniform sampler2D texSampler ;
varying vec4 fcolor;
varying vec2 ftex;

uniform bool drawTexture;

void main() {
	if(drawTexture)
	{
		gl_FragColor = texture2D( texSampler , ftex );
	}
	else
	{
		gl_FragColor = fcolor;
	}
};