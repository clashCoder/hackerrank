

//Write your code here

class Flower {
    public Flower() {}
    
    public String whats_Your_Name() {
        return "I have many names and types";
    }
}

class Jasmine extends Flower {
    public Jasmine() {}
    
    @Override
    public String whats_Your_Name() {
        return "Jasmine";
    }
}

class Lily extends Flower {
    public Lily() {} 
    
    @Override
    public String whats_Your_Name() {
        return "Lily";
    }
}

class Lotus extends Flower {
    public Lotus() {}
    
    @Override
    public String whats_Your_Name() {
        return "Lotus";
    }
}

class State {
    private Flower f;
    public State() {
        f = new Flower();
    }
    
    public Flower your_National_Flower() {
        return f;
    }
}

class WestBengal extends State {
    private Jasmine j;
    public WestBengal() {
        j = new Jasmine();
    }
    
    @Override
    public Jasmine your_National_Flower() {
        return j;
    }
}

class Karnataka extends State {
    private Lotus l;
    public Karnataka() {
        l = new Lotus();
    }
    
    @Override
    public Lotus your_National_Flower() {
        return l;
    }
}

class AndhraPradesh extends State {
    private Lily l;
    public AndhraPradesh() {
        l = new Lily();
    }
    
    @Override
    public Lily your_National_Flower() {
        return l;
    }
}