#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 texCord;
out vec2 v_texCord;

uniform mat4 v_model;
uniform mat4 v_view;
uniform mat4 v_projection;

void main()
{
   gl_Position = v_projection * v_view * v_model * vec4(aPos, 1.0);
   v_texCord = texCord;
}

#shader fragment
#version 330 core
out vec4 FragColor;
in vec2 v_texCord;

uniform sampler2D u_Texture1;
uniform sampler2D u_Texture2;

void main()
{
   vec4 texColor1 = texture(u_Texture1, v_texCord);
   vec4 texColor2 = texture(u_Texture2, v_texCord);
   FragColor = mix(texColor1, texColor2, 0.2) ;
}
