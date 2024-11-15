import graphene
# Definición del tipo de objeto Usuario
class User(graphene.ObjectType):
    id = graphene.Int()
    name = graphene.String()
    email = graphene.String()

# Consulta principal
class Query(graphene.ObjectType):
    users = graphene.List(User)

    def resolve_users(self, info):
        # Aquí puedes reemplazar con una consulta a tu base de datos, por ejemplo.
        return [
            User(id=1, name="Juan Pérez", email="juan@example.com"),
            User(id=2, name="Ana García", email="ana@example.com"),
            User(id=3, name="Carlos Martínez", email="carlos@example.com")
        ]

# Definición del esquema
schema = graphene.Schema(query=Query)
