package com.neb.common;

/**
 * Created by benlindsey on 07/01/2016.
 */
public class StringRandomSource {
    public String name;
    public RandomSet set;
    public String from;
    public String to;

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        StringRandomSource that = (StringRandomSource) o;

        if (!name.equals(that.name)) return false;
        if (set != that.set) return false;
        if (!from.equals(that.from)) return false;
        return to.equals(that.to);

    }

    @Override
    public int hashCode() {
        int result = name.hashCode();
        result = 31 * result + set.hashCode();
        result = 31 * result + from.hashCode();
        result = 31 * result + to.hashCode();
        return result;
    }

    public StringRandomSource(String name, RandomSet set, String from, String to) {
        this.name = name;
        this.set = set;
        this.from = from;
        this.to = to;
    }
}
