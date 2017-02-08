#version 150

uniform sampler2D Resource;

in vec2 tex_coord;

void main()
{
    // Read and apply a color from the Resource
    gl_FragColor = texture2D(Resource, tex_coord);
}
