module FlightPhysics

include("constants.jl")

include("gravitational_acceleration.jl")
export gravitational_acceleration

include("international_standard_atmosphere.jl")
export isa_state
public ISAState

include("altitude.jl")
export geometric_to_geopotential_altitude
export geopotential_to_geometric_altitude

end
