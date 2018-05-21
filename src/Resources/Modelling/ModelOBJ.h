#ifndef MODELOBJ_H
#define MODELOBJ_H

#include "ModelBase.h"

	/**
	 * Contains information about a static 3D model
	 */
class ModelOBJ  : public ModelBase
{
public:
		/**
		 * Constructor
		 */
	ModelOBJ();
		/**
		 * Constructor.
		 * @param[in] vaoId The ID of the model.
		 * @param[in] vertexCount The number of verticies.
		 */
	ModelOBJ(int vaoId, int vertexCount);
		/**
		 * Copy constructor
		 */
	ModelOBJ(const ModelOBJ & other);
		/**
		 * Destructor
		 */
	~ModelOBJ();

	

private:

private:
	
};

#endif