#version 400
uniform sampler2D texture;
varying vec2 position;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    //gl_FragColor = vec4(0.0, 1.0, 1.0, 1.0) * pixel; //1, 1, 2, 0.8 * pixel for night colors.
	gl_FragColor.r = 1.0 * pixel;
	gl_FragColor.g = 1.0 * pixel;
	gl_FragColor.b = 1.5 * pixel;
	gl_FragColor.a = 0.6;
	
}
