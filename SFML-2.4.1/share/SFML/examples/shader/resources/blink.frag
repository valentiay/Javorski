uniform sampler2D Resource;
uniform float blink_alpha;

void main()
{
    vec4 pixel = gl_Color;
    pixel.a = blink_alpha;
    gl_FragColor = pixel;
}
