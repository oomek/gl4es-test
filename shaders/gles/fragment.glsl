uniform float uTime;
varying vec2 tcoord;
uniform sampler2D tex;

vec2 uv;
float lum;
void main(void)
{
	float wave_size = 15.0;
	uv = tcoord / 2.1 + 0.5;
	float wave = uTime * 0.05 + uv.x * wave_size;
	uv.x += sin(wave) * 0.005;
	uv.y += cos(wave) * 0.01;
	lum = sin(wave) / 4.0 + 0.75;
    gl_FragColor = texture2D(tex,uv) * vec4(lum, lum, 0.5 + lum / 2.0,1.0);
}
