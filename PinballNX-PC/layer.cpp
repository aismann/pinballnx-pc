#include "layer.h"

Layer::Layer(SceneElement* root, b2World& world, int layerID) {
    int numShapes = m_layerData.at(layerID).size();
    for (int i = 0; i < numShapes; i++) {
        loadShape(m_layerData.at(layerID).at(i), root, world, layerID);
    }
#if !DEBUG
	Texture* texture = new Texture();
	texture->loadFromFile("data/layer" + std::to_string(layerID) + ".png");
	Sprite* sprite = new Sprite();
	sprite->setTexture(*texture);
	SceneElement* elt = new SceneElement(sprite);
    // Multiply by 2 because rendering layers have a gap so the pinball
    // can be rendered above the layer it is on.
    elt->setLayer(layerID * 2);
    root->add(elt);
#endif
}

void Layer::loadShape(std::vector<float> points, SceneElement* root, b2World& world, int layerID) {
    b2Vec2* vs = getVertexArray(points);
    b2ChainShape chain;
    chain.CreateChain(vs, points.size() / 2);
    free(vs);

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.filter.maskBits = 0xFFFF;
    fixtureDef.filter.categoryBits = 1 << layerID;
    body->CreateFixture(&fixtureDef);

#if DEBUG
    // Debug graphics
    // The texture loading should be done elsewhere.
    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    if (layerID == 0)
        cshape->setFillColor(Color::Cyan);
    if (layerID == 3)
        cshape->setFillColor(Color::Red);
    renderer->add(cshape);
#endif
}

int Layer::getLayerID() {
    return m_layerID;
}
