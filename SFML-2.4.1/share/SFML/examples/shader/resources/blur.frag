uniform sampler2D Resource;
uniform float blur_radius;

void main()
{
    vec2 offx = vec2(blur_radius, 0.0);
    vec2 offy = vec2(0.0, blur_radius);

    vec4 pixel = texture2D(Resource, gl_TexCoord[0].xy)               * 4.0 +
                 texture2D(Resource, gl_TexCoord[0].xy - offx)        * 2.0 +
                 texture2D(Resource, gl_TexCoord[0].xy + offx)        * 2.0 +
                 texture2D(Resource, gl_TexCoord[0].xy - offy)        * 2.0 +
                 texture2D(Resource, gl_TexCoord[0].xy + offy)        * 2.0 +
                 texture2D(Resource, gl_TexCoord[0].xy - offx - offy) * 1.0 +
                 texture2D(Resource, gl_TexCoord[0].xy - offx + offy) * 1.0 +
                 texture2D(Resource, gl_TexCoord[0].xy + offx - offy) * 1.0 +
                 texture2D(Resource, gl_TexCoord[0].xy + offx + offy) * 1.0;

    gl_FragColor =  gl_Color * (pixel / 16.0);
}
