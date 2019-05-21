attribute vec4 vertex;
varying vec2 tcoord;

void main(void)
{
        vec4 pos = vertex;
        tcoord.xy = pos.xy;
        gl_Position = pos;
}
