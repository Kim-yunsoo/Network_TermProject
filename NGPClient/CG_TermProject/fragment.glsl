#version 330 core

in vec3 FragPos;			//--- ��ġ��
in vec3 Normal;				//--- ���ؽ� ���̴����� ���� ��ְ�
in vec2 TexCoord;			//--- �ؽ�ó ��ǥ

in vec3 yanggang;

out vec4 FragColor;			//--- ���� ��ü�� �� ����

uniform vec3 lightPos;		//--- ������ ��ġ
uniform vec3 lightColor;	//--- ������ ��
uniform vec4 objectColor;	//--- ��ü�� ��

uniform vec3 viewPos;		//--- ī�޶� ��ġ

uniform sampler2D outTexture;	//--- �ؽ�ó ���÷�

uniform int selectColor;	//--- �ؽ�ó�� �׸��� ������ �׸��� ����(�⺻-����)

void main()
{
	float ambientLight = 1.0;										//--- �ֺ� ���� ���: 0.0 �� ambientLight �� 1.
	vec3 ambient = ambientLight * lightColor;						//--- �ֺ� ���� ��

	vec3 normalVector = normalize (Normal);							//--- �븻���� ����ȭ�Ѵ�.
	vec3 lightDir = normalize (lightPos - FragPos);					//--- ǥ��� ������ ��ġ�� ������ ������ �����Ѵ�.

	float diffuseLight = max (dot (normalVector, lightDir), 0.0);	//--- N�� L�� ���� ������ ���� ���� (���� ���� ���� �� ���� �Ѵ�.)
	vec3 diffuse = diffuseLight * lightColor;						//--- ����ݻ������� = ����ݻ簪 * ��������


	int shininess = 128;				//--- ���� ���
										//--- ��¦�̴� ���̶���Ʈ�� �����Ѵ�.
										//--- �����ڰ� ���� �Ի簢�� ���� ���� �ݻ簢 �αٿ� ��ġ�� ��� �Ի�� ���� ���θ� �ν��ϸ� ���̶���Ʈ�� �����.
										//--- �ſ� �ݻ� ������ ������ shininess (���� ���) ������ �߰�: shininess �� ������ ���� ������ ���̶���Ʈ�� �����ȴ�.

	vec3 viewDir = normalize (viewPos - FragPos);					//--- �������� ����
	vec3 reflectDir = reflect (-lightDir, normalVector);			//--- �ݻ� ����: reflect �Լ� - �Ի� ������ �ݻ� ���� ���

	float specularLight = max (dot (viewDir, reflectDir), 0.0);		//--- V�� R�� ���������� ���� ����: ���� ����
	specularLight = pow(specularLight, shininess);					//--- shininess ���� ���־� ���̶���Ʈ�� ������ش�.
	vec3 specular = specularLight * lightColor;						//--- �ſ� �ݻ� ������: �ſ�ݻ簪 * ��������

	
	vec4 result;
	if(1 == selectColor)			// 1�̸� �ؽ�ó, �ƴϸ� objectColor
		result = texture(outTexture, TexCoord) * vec4((ambient + diffuse + specular), 1.0);
	else if(2 == selectColor)
		result = vec4(yanggang, 1.0) * vec4((ambient + diffuse + specular), 1.0);
	else
		result = vec4((ambient + diffuse + specular), 1.f) * objectColor;  		//--- ���� ���� ������ �ȼ� ����: (�ֺ����� + ����ݻ����� + �ſ�ݻ�����) * ��ü ����

	
	FragColor = result;												//--- �ȼ� ���� ���
}

