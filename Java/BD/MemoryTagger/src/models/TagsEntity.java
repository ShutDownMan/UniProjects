package models;

import javax.persistence.*;
import java.util.Collection;

@Entity
@Table(name = "tags", schema = "public", catalog = "memorytaggerdb")
public class TagsEntity {
    private Long id;
    private String name;
    private Collection<MemoryTagEntity> memoryTagsById;

    @Id
    @Column(name = "id", nullable = false)
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @Basic
    @Column(name = "name", nullable = false, length = 64)
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        TagsEntity that = (TagsEntity) o;

        if (id != null ? !id.equals(that.id) : that.id != null) return false;
        if (name != null ? !name.equals(that.name) : that.name != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = id != null ? id.hashCode() : 0;
        result = 31 * result + (name != null ? name.hashCode() : 0);
        return result;
    }

    @OneToMany(mappedBy = "tagsByIdTags")
    public Collection<MemoryTagEntity> getMemoryTagsById() {
        return memoryTagsById;
    }

    public void setMemoryTagsById(Collection<MemoryTagEntity> memoryTagsById) {
        this.memoryTagsById = memoryTagsById;
    }
}
