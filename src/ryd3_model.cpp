#include "ryd3_model.h"

#include "ryd3_texture.h"

#include "glm/gtc/quaternion.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Model::~Model() {
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);
	glDeleteBuffers(1, &normalBuffer);
	glDeleteBuffers(1, &indicesBuffer);
}

bool Model::load(const std::string &filename) {
	Assimp::Importer importer;

	const aiScene *scene = importer.ReadFile(filename,
		aiProcess_CalcTangentSpace | aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

	if (!scene) {
		std::cerr << "Unable to open model file: " << filename << std::endl
			<< "Assimp error: " << importer.GetErrorString();
		return false;
	}

	const int vertexTotalSize = sizeof(aiVector3D)*2+sizeof(aiVector2D);
	int totalVertices = 0;

	for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
		aiMesh *mesh = scene->mMeshes[i];
		for (unsigned int j = 0; j < mesh->mNumVertices; j++) {
			aiVector3D pos = mesh->mVertices[j];
			aiVector3D uv = mesh->mTextureCoords[0][j];
			aiVector3D normal = mesh->mNormals[j];
			vertices.push_back(glm::vec3(pos.x, pos.y, pos.x));
			uvs.push_back(glm::vec2(uv.x, uv.y));
			normals.push_back(glm::vec3(normal.x, normal.y, normal.z));
		}

		for (unsigned int j = 0; j < mesh->mNumFaces; j++) {
			for (unsigned int k = 0; k < 3; k++) {
				indices.push_back(mesh->mFaces[j].mIndices[k]);
			}
		}
	}

	for (unsigned int i = 0; i < scene->mNumMaterials; i++) {
		const aiMaterial *material = scene->mMaterials[i];
		aiString path;

		if (material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS) {
			std::string finalPath = path.data;
			texture = ResourceManager::getResourceManager()->getResource<Texture>(finalPath);
			break; // I'm assuming each model will have one texture right now
		}
	}

	setupArrayObject();
}

void Model::setupArrayObject() {
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
		&vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0],
		GL_STATIC_DRAW);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3),
		&normals[0], GL_STATIC_DRAW);

	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ARRAY_BUFFER, indices.size() * sizeof(unsigned short),
		&indices[0], GL_STATIC_DRAW);
}

void Model::drawModel() {
	glActiveTexture(GL_TEXTURE0);
	texture->bindTexture();

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}